export type SiteProject = {
  title: string;
  subtitle: string;
  description: string;
  status: string;
  href: string;
  image: string;
  links: Array<{
    label: string;
    href: string;
    disabled?: boolean;
  }>;
};

export const siteInfo = {
  name: 'Spiral Hand',
  subtitle: 'Nature-inspired Compliant Hand',
  description:
    'Spiral Hand is a dexterous hand research project focused on compliant joint design, embedded sensing, safe interaction, and robust manipulation.',
  noteTitle: 'Get Started!',
  note: ['Print within 4h', 'Assemble within 40min'],
};

export const aboutInfo = {
  title: 'About Us',
  eyebrow: 'Spiral Hand team',
  intro:
    'We are a research team working on dexterous robotic hands, compliant mechanisms, and proprioception. Welcome to join our journey!',
  affiliation: 'School of Automation, Beijing Institute of Technology',
  members: [
    { name: 'Haoyang Li', email: 'bithaoyangli@163.com' },
    { name: 'Yibo Wen', email: 'wenyibo1105@gmail.com' },
    { name: 'Yiheng Xu', email: 'xyh15523@gmail.com' },
    { name: 'Yixiang Fan', email: 'fanyixiang318@gmail.com' },
    { name: 'Yufeng Yue', email: 'yueyufeng@bit.edu.cn' },
  ],
};

export const siteProjects: SiteProject[] = [
  {
    title: 'PDS Joint',
    subtitle: 'Parametric double-spiral compliant joint for dexterous hands',
    description:
      'Inspired by fern fronds, we proposed a parametric double-spiral compliant joint for dexterous hands, including joint geometry, stiffness tuning, embedded inductive sensing, calibration, and hand-level demonstrations.',
    status: 'IROS 2026',
    href: '/projects/pds-joint',
    image: '/assets/pds/figures/hero.png',
    links: [
      { label: 'Project page', href: '/projects/pds-joint' },
      { label: 'Paper', href: 'https://arxiv.org/pdf/2606.24377' },
      { label: 'Video', href: '/projects/pds-joint#video' },
      { label: 'CAD', href: 'https://github.com/spiralhand/spiralhand.github.io/tree/main/CAD' },
      { label: 'PCB', href: 'https://github.com/spiralhand/spiralhand.github.io/tree/main/PCB' },
    ],
  },
];
