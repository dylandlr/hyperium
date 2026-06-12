const seedTitle = document.querySelector('#seedTitle');
const textureType = document.querySelector('#textureType');
const movementName = document.querySelector('#movementName');
const presetButton = document.querySelector('#presetButton');
const generateButton = document.querySelector('#generateButton');
const seedButtons = [...document.querySelectorAll('.seed-buttons button')];
const motionButtons = [...document.querySelectorAll('.motion-buttons button')];
const morphPad = document.querySelector('#morphPad');
const morphDot = document.querySelector('#morphDot');
const morphLabel = document.querySelector('#morphLabel');

const seedStates = {
  glassy: {
    title: 'glassy · hard · glitchy · digital',
    preset: 'pink glass lead',
    texture: 'glass',
    movement: 'Glitch → Wave Position'
  },
  cute: {
    title: 'cute · medium · pulsing · airy',
    preset: 'candy pixel pluck',
    texture: 'air',
    movement: 'Pulse → Filter Cutoff'
  },
  dreamy: {
    title: 'dreamy · soft · blooming · tape',
    preset: 'bedroom shimmer pad',
    texture: 'tape',
    movement: 'Bloom → Space Mix'
  },
  crushed: {
    title: 'crushed · hard · drifting · digital',
    preset: 'crushed candy bass',
    texture: 'bits',
    movement: 'Drift → Crush Amount'
  },
  vocal: {
    title: 'vocal · medium · orbiting · breath',
    preset: 'plastic vocal arp',
    texture: 'breath',
    movement: 'Orbit → Formant'
  }
};

function drawWave(canvasId, variant = 0) {
  const canvas = document.querySelector(canvasId);
  const ctx = canvas.getContext('2d');
  const width = canvas.width;
  const height = canvas.height;
  ctx.clearRect(0, 0, width, height);

  const gradient = ctx.createLinearGradient(0, 0, width, 0);
  gradient.addColorStop(0, '#56d8ff');
  gradient.addColorStop(0.55, '#9b5cff');
  gradient.addColorStop(1, '#ff7dcd');

  ctx.lineWidth = 3;
  ctx.strokeStyle = gradient;
  ctx.shadowColor = 'rgba(155, 92, 255, 0.55)';
  ctx.shadowBlur = 14;
  ctx.beginPath();

  for (let x = 0; x < width; x += 2) {
    const t = x / width;
    const wave =
      Math.sin((t * Math.PI * 2 * (variant + 2))) * 0.32 +
      Math.sin((t * Math.PI * 2 * (variant + 5)) + 0.8) * 0.16 +
      Math.sin((t * Math.PI * 2 * 13) + variant) * 0.05;
    const y = height / 2 + wave * height * 0.72;
    if (x === 0) ctx.moveTo(x, y);
    else ctx.lineTo(x, y);
  }

  ctx.stroke();
}

function setSeed(seed) {
  const state = seedStates[seed];
  if (!state) return;

  seedButtons.forEach((button) => {
    button.classList.toggle('active', button.dataset.seed === seed);
  });

  seedTitle.textContent = state.title;
  textureType.textContent = state.texture;
  movementName.textContent = state.movement;
  presetButton.textContent = state.preset;
}

seedButtons.forEach((button) => {
  button.addEventListener('click', () => setSeed(button.dataset.seed));
});

motionButtons.forEach((button) => {
  button.addEventListener('click', () => {
    motionButtons.forEach((item) => item.classList.remove('active'));
    button.classList.add('active');
    movementName.textContent = `${button.textContent} → Wave Position`;
  });
});

generateButton.addEventListener('click', () => {
  const seeds = Object.keys(seedStates);
  const next = seeds[Math.floor(Math.random() * seeds.length)];
  setSeed(next);
  generateButton.animate(
    [
      { transform: 'scale(1)', filter: 'brightness(1)' },
      { transform: 'scale(1.06)', filter: 'brightness(1.45)' },
      { transform: 'scale(1)', filter: 'brightness(1)' }
    ],
    { duration: 360, easing: 'ease-out' }
  );
});

function updateMorphFromEvent(event) {
  const rect = morphPad.getBoundingClientRect();
  const x = Math.min(Math.max(event.clientX - rect.left, 0), rect.width);
  const y = Math.min(Math.max(event.clientY - rect.top, 0), rect.height);
  const xPct = x / rect.width;
  const yPct = y / rect.height;

  morphDot.style.left = `${xPct * 100}%`;
  morphDot.style.top = `${yPct * 100}%`;
  morphPad.setAttribute('aria-valuenow', String(Math.round(xPct * 100)));

  const horizontal = xPct < 0.38 ? 'soft' : xPct > 0.62 ? 'crush' : '';
  const vertical = yPct < 0.38 ? 'dream' : yPct > 0.62 ? 'glitch' : '';
  morphLabel.textContent = [vertical, horizontal].filter(Boolean).join(' + ') || 'center';
}

let draggingMorph = false;

morphPad.addEventListener('pointerdown', (event) => {
  draggingMorph = true;
  morphPad.setPointerCapture(event.pointerId);
  updateMorphFromEvent(event);
});

morphPad.addEventListener('pointermove', (event) => {
  if (draggingMorph) updateMorphFromEvent(event);
});

morphPad.addEventListener('pointerup', () => {
  draggingMorph = false;
});

morphPad.addEventListener('keydown', (event) => {
  const step = event.shiftKey ? 10 : 4;
  const currentLeft = parseFloat(morphDot.style.left || '50');
  const currentTop = parseFloat(morphDot.style.top || '50');
  let nextLeft = currentLeft;
  let nextTop = currentTop;

  if (event.key === 'ArrowLeft') nextLeft -= step;
  if (event.key === 'ArrowRight') nextLeft += step;
  if (event.key === 'ArrowUp') nextTop -= step;
  if (event.key === 'ArrowDown') nextTop += step;

  nextLeft = Math.min(Math.max(nextLeft, 0), 100);
  nextTop = Math.min(Math.max(nextTop, 0), 100);
  morphDot.style.left = `${nextLeft}%`;
  morphDot.style.top = `${nextTop}%`;

  const horizontal = nextLeft < 38 ? 'soft' : nextLeft > 62 ? 'crush' : '';
  const vertical = nextTop < 38 ? 'dream' : nextTop > 62 ? 'glitch' : '';
  morphLabel.textContent = [vertical, horizontal].filter(Boolean).join(' + ') || 'center';
});

drawWave('#waveA', 1);
drawWave('#waveB', 3);
