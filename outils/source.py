# Fabrique un son de départ pour les essais : guitare pincée (arpèges) + petite batterie.
# Usage : python3 source.py sortie.wav [durée en s]
import sys, wave, numpy as np
sr = 48000
dur = float(sys.argv[2]) if len(sys.argv) > 2 else 24.0
n = int(sr * dur)
rng = np.random.default_rng(3)
out = np.zeros((n, 2))

def corde(f, t0, longueur=2.5, amp=0.35, pan=0.0):
    N = int(sr / f)
    buf = rng.uniform(-1, 1, N)
    buf = np.convolve(buf, [0.5, 0.5], 'same')
    m = int(longueur * sr)
    y = np.zeros(m)
    idx = 0
    for i in range(m):
        a = buf[idx]; b = buf[(idx + 1) % N]
        y[i] = a
        buf[idx] = 0.996 * 0.5 * (a + b)
        idx = (idx + 1) % N
    i0 = int(t0 * sr); i1 = min(n, i0 + m)
    y = y[:i1 - i0] * amp
    out[i0:i1, 0] += y * (1 - pan) ; out[i0:i1, 1] += y * (1 + pan)

bpm = 100; temps = 60 / bpm
# arpèges en Mi mineur / Do / Ré
accords = [(82.4, 123.5, 164.8, 196.0, 246.9), (130.8, 164.8, 196.0, 261.6, 329.6), (146.8, 220.0, 293.7, 370.0, 440.0), (82.4, 123.5, 164.8, 196.0, 246.9)]
t = 0.0; k = 0
while t < dur - 1:
    acc = accords[(k // 8) % 4]
    corde(acc[k % 5] if k % 2 == 0 else acc[(k * 3) % 5], t, pan=0.3 * np.sin(k))
    t += temps / 2; k += 1

def kick(t0):
    m = int(0.4 * sr); tt = np.arange(m) / sr
    f = 50 + 120 * np.exp(-tt * 30)
    y = np.sin(2 * np.pi * np.cumsum(f) / sr) * np.exp(-tt * 9) * 0.7
    i0 = int(t0 * sr); i1 = min(n, i0 + m); out[i0:i1] += y[:i1 - i0, None]
def snare(t0):
    m = int(0.25 * sr); tt = np.arange(m) / sr
    y = (rng.uniform(-1, 1, m) * 0.4 + np.sin(2 * np.pi * 190 * tt) * 0.3) * np.exp(-tt * 18)
    i0 = int(t0 * sr); i1 = min(n, i0 + m); out[i0:i1] += y[:i1 - i0, None] * 0.6
def hat(t0):
    m = int(0.05 * sr); tt = np.arange(m) / sr
    y = np.diff(rng.uniform(-1, 1, m + 1)) * np.exp(-tt * 80) * 0.12
    i0 = int(t0 * sr); i1 = min(n, i0 + m); out[i0:i1, 0] += y[:i1 - i0]; out[i0:i1, 1] += y[:i1 - i0] * 0.7

b = 0
while b * temps < dur - 0.5:
    t0 = b * temps
    if b % 4 in (0, 2) or b % 8 == 7: kick(t0)
    if b % 4 in (1, 3): snare(t0)
    hat(t0); hat(t0 + temps / 2)
    b += 1

out *= 0.5 / np.max(np.abs(out))
with wave.open(sys.argv[1], 'wb') as w:
    w.setnchannels(2); w.setsampwidth(2); w.setframerate(sr)
    w.writeframes((np.clip(out, -1, 1) * 32767).astype('<i2').tobytes())
