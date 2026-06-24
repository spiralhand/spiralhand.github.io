export type ProjectLink = {
  label: string;
  href: string;
  status?: 'ready' | 'coming-soon';
};

export type MediaItem = {
  title: string;
  description: string;
  src: string;
  kind: 'image' | 'video';
  fit?: 'contain' | 'cover';
};

export const pdsJoint = {
  title: 'PDS Joint: A Parametric Double-Spiral Joint Tailored for Dexterous Hands',
  titleLines: ['PDS Joint: A Parametric Double-Spiral', 'Joint Tailored for Dexterous Hands'],
  shortTitle: 'PDS Joint',
  venue: 'IROS 2026',
  authors: ['Haoyang Li', 'Yibo Wen', 'Yiheng Xu', 'Yixiang Fan', 'Yufeng Yue*'],
  summary:
    'This work studies a parametric double-spiral compliant joint for dexterous hands, including joint geometry, stiffness tuning, embedded inductive sensing, calibration, and hand-level demonstrations.',
  abstract:
    'Compliant joints can embed safety and adaptability into dexterous hands, but achieving large-stroke anthropomorphic motion while maintaining joint-specific, direction-dependent stiffness and reliable proprioception remains challenging. This paper presents the PDS joint, a parametric double-spiral compliant joint that enables systematic shaping of directional stiffness across multiple deformation modes, including flexion/extension, abduction/adduction, and pronation/supination. We instantiate the joint using Archimedean and logarithmic spiral templates for different hand joints and introduce an asymmetry ratio to tailor stiffness distributions for both grasp stability and hyperextension resistance. To make the joint practically usable under large deformation, we co-design embedded inductive proprioception and propose a learning-based calibration pipeline that maps raw inductive signals to joint states using ArUco-marker tracking. Experiments characterize the stiffness landscapes across geometric parameters and demonstrate a non-monotonic dependence of lateral support on asymmetry, indicating the importance of principled parameter tuning. For joint-state estimation in the most challenging abduction/adduction motion, an MLP-based mapping reduces error compared with conventional curve fitting by 59.2%. Finally, we integrate the proposed joints into an open-source dexterous hand as a demonstration platform and achieved full success rate in adaptive grasping tests and safe, contact-rich human-involved interactions.',
  keywords: ['Compliant joint', 'Dexterous hand', 'Spiral mechanism', 'Proprioception', 'Inductive sensing'],
  links: [
    { label: 'Paper PDF', href: 'https://arxiv.org/pdf/2606.24377' },
    { label: 'Video', href: '/projects/pds-joint#video' },
    { label: 'BibTeX', href: '/projects/pds-joint#citation' },
    { label: 'CAD', href: 'https://github.com/spiralhand/spiralhand.github.io/tree/main/CAD' },
    { label: 'PCB', href: 'https://github.com/spiralhand/spiralhand.github.io/tree/main/PCB' },
  ] satisfies ProjectLink[],
  figures: {
    overview: '/assets/pds/figures/hero.png',
    design: '/assets/pds/figures/design-overview.png',
    spiral: '/assets/pds/figures/spiral-template.png',
    sensing: '/assets/pds/figures/sensing.png',
    stiffness: '/assets/pds/figures/results-stiffness.png',
    calibration: '/assets/pds/figures/results-calibration.png',
    grasping: '/assets/pds/figures/grasping-demo.png',
    interaction: '/assets/pds/figures/interaction-demo.png',
  },
  video: '/assets/pds/intro-video.mp4',
  sections: [
    {
      title: 'Joint design',
      text: 'The joint is defined by double-spiral compliant elements and a small set of geometric parameters. The paper studies how these parameters affect deformation modes relevant to dexterous hands.',
    },
    {
      title: 'Stiffness characterization',
      text: 'Mechanical tests are used to measure directional stiffness and compare different geometric choices, including the effect of asymmetry on lateral support.',
    },
    {
      title: 'Embedded proprioception',
      text: 'An inductive sensing module is integrated with the compliant joint, and a calibration pipeline maps raw sensor readings to joint states under large deformation.',
    },
    {
      title: 'Hand demonstration',
      text: 'The joints are installed in a dexterous hand platform for adaptive grasping and human-involved interaction experiments.',
    },
  ],
  media: [
    {
      title: 'System overview',
      description: 'Overview of the PDS-joint-based dexterous hand and sensing setup.',
      src: '/assets/pds/figures/hero.png',
      kind: 'image',
      fit: 'contain',
    },
    {
      title: 'Joint design',
      description: 'Design variables and double-spiral joint structure.',
      src: '/assets/pds/figures/design-overview.png',
      kind: 'image',
      fit: 'contain',
    },
    {
      title: 'Spiral templates',
      description: 'Archimedean and logarithmic spiral templates used in the joint design.',
      src: '/assets/pds/figures/spiral-template.png',
      kind: 'image',
      fit: 'contain',
    },
    {
      title: 'Sensing module',
      description: 'Inductive sensing hardware and calibration setup.',
      src: '/assets/pds/figures/sensing.png',
      kind: 'image',
      fit: 'contain',
    },
    {
      title: 'Stiffness tests',
      description: 'Experimental results for joint stiffness characterization.',
      src: '/assets/pds/figures/results-stiffness.png',
      kind: 'image',
      fit: 'contain',
    },
    {
      title: 'Calibration results',
      description: 'Joint-state estimation results from the calibration pipeline.',
      src: '/assets/pds/figures/results-calibration.png',
      kind: 'image',
      fit: 'contain',
    },
    {
      title: 'Grasping demonstration',
      description: 'Adaptive grasping tests with the dexterous hand platform.',
      src: '/assets/pds/figures/grasping-demo.png',
      kind: 'image',
      fit: 'contain',
    },
    {
      title: 'Human interaction',
      description: 'Contact-rich interaction examples with the hand platform.',
      src: '/assets/pds/figures/interaction-demo.png',
      kind: 'image',
      fit: 'contain',
    },
  ] satisfies MediaItem[],
  citation: `@inproceedings{li2026pdsjoint,
  title = {PDS Joint: A Parametric Double-Spiral Joint Tailored for Dexterous Hands},
  author = {Li, Haoyang and Wen, Yibo and Xu, Yiheng and Fan, Yixiang and Yue, Yufeng},
  booktitle = {IEEE/RSJ International Conference on Intelligent Robots and Systems (IROS)},
  year = {2026}
}`,
};
