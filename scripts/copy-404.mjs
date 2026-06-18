import { copyFileSync, mkdirSync } from 'node:fs';
import { dirname } from 'node:path';

const fallbackRoutes = ['404.html', 'about/index.html', 'projects/pds-joint/index.html'];

for (const route of fallbackRoutes) {
  const outputPath = `dist/${route}`;
  const outputDir = dirname(outputPath);
  if (outputDir !== 'dist') {
    mkdirSync(outputDir, { recursive: true });
  }
  copyFileSync('dist/index.html', outputPath);
}
