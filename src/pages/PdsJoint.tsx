import { motion, type MotionProps } from 'framer-motion';
import { CitationBlock } from '../components/CitationBlock';
import { FigureCarousel } from '../components/FigureCarousel';
import { LinkButton } from '../components/LinkButton';
import { MemphisShape } from '../components/MemphisShape';
import { pdsJoint } from '../content/pdsJoint';

const appear: MotionProps = {
  initial: { opacity: 0, y: 18 },
  whileInView: { opacity: 1, y: 0 },
  viewport: { once: true, margin: '-80px' },
  transition: { duration: 0.45, ease: 'easeOut' },
};

export function PdsJoint() {
  return (
    <div className="page paper-page">
      <section className="paper-header poster-grid">
        <MemphisShape variant="dots" className="shape-one" />
        <MemphisShape variant="checker" className="shape-two" />
        <div className="paper-title-block">
          <p className="venue-badge">{pdsJoint.venue}</p>
          <h1>
            {pdsJoint.titleLines.map((line) => (
              <span key={line}>{line}</span>
            ))}
          </h1>
          <p className="authors">{pdsJoint.authors.join(', ')}</p>
          <p className="paper-summary">{pdsJoint.summary}</p>
          <div className="hero-actions compact-actions">
            {pdsJoint.links.map((link, index) => (
              <LinkButton key={link.label} {...link} variant={index === 0 ? 'primary' : 'secondary'} />
            ))}
          </div>
        </div>
        <div className="paper-header-figure" aria-hidden="true">
          <img src={pdsJoint.figures.overview} alt="" />
        </div>
      </section>

      <motion.section className="section abstract-section" {...appear}>
        <div className="section-label">Abstract</div>
        <p>{pdsJoint.abstract}</p>
        <div className="keyword-row">
          {pdsJoint.keywords.map((keyword) => (
            <span key={keyword}>{keyword}</span>
          ))}
        </div>
      </motion.section>

      <motion.section className="section research-sections" {...appear}>
        <div className="section-heading compact-heading">
          <div>
            <div className="section-label">Paper contents</div>
            <h2>Main components of the work</h2>
          </div>
        </div>
        <div className="research-section-grid">
          {pdsJoint.sections.map((section, index) => (
            <article className="research-section-card" key={section.title}>
              <span>{String(index + 1).padStart(2, '0')}</span>
              <h3>{section.title}</h3>
              <p>{section.text}</p>
            </article>
          ))}
        </div>
      </motion.section>

      <motion.section className="section video-section" id="video" {...appear}>
        <div>
          <div className="section-label">Video</div>
          <h2>Project video</h2>
        </div>
        <div className="wide-video offset-frame">
          <video src={pdsJoint.video} controls playsInline preload="metadata" poster="/assets/pds/figures/video-cover.png" />
        </div>
      </motion.section>

      <motion.section className="section figure-gallery" {...appear}>
        <div className="section-heading compact-heading">
          <div>
            <div className="section-label">Figures</div>
            <h2>Paper figures and demonstrations</h2>
          </div>
        </div>
        <FigureCarousel items={pdsJoint.media} />
      </motion.section>

      <CitationBlock citation={pdsJoint.citation} />

      <footer className="site-footer">
        <a href="#/">Back to Spiral Hand</a>
        <span>© 2026 Spiral Hand. All rights reserved.</span>
      </footer>
    </div>
  );
}
