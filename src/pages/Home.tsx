import { motion, type MotionProps } from 'framer-motion';
import { ArrowUpRight } from 'lucide-react';
import { MemphisShape } from '../components/MemphisShape';
import { aboutInfo, siteInfo, siteProjects } from '../content/site';

const appear: MotionProps = {
  initial: { opacity: 0, y: 18 },
  whileInView: { opacity: 1, y: 0 },
  viewport: { once: true, margin: '-80px' },
  transition: { duration: 0.45, ease: 'easeOut' },
};

function renderHighlightedTime(line: string) {
  const match = line.match(/^(.*?)(\d+\s*(?:h|min|hours?|minutes?))(.*)$/i);

  if (!match) {
    return line;
  }

  return (
    <>
      {match[1]}
      <strong className="time-highlight">{match[2].replace(/\s+/g, '')}</strong>
      {match[3]}
    </>
  );
}

export function Home() {
  return (
    <div className="page home-page">
      <section className="home-intro poster-grid">
        <MemphisShape variant="dots" className="shape-one" />
        <MemphisShape variant="checker" className="shape-two" />
        <div className="home-intro-copy">
          <p className="eyebrow">Research project</p>
          <h1>{siteInfo.name}</h1>
          <p className="home-subtitle">{siteInfo.subtitle}</p>
          <p className="home-description">{siteInfo.description}</p>
        </div>
        <div className="home-note-card">
          <h2>{siteInfo.noteTitle}</h2>
          <div className="home-note-list">
            {siteInfo.note.map((line) => (
              <p key={line}>{renderHighlightedTime(line)}</p>
            ))}
          </div>
        </div>
      </section>

      <motion.section className="section project-index" id="projects" {...appear}>
        <div className="section-heading compact-heading">
          <div>
            <div className="section-label">Projects</div>
            <h2>Spiral Hand Projects</h2>
          </div>
        </div>

        <div className="project-card-grid">
          {siteProjects.map((project) => (
            <article className="project-card" key={project.title}>
              <a className="project-card-image" href={project.href} aria-label={`Open ${project.title}`}>
                <img src={project.image} alt={`${project.title} overview`} loading="lazy" />
              </a>
              <div className="project-card-body">
                <div className="project-card-meta">
                  <span>{project.status}</span>
                </div>
                <h3>
                  <a href={project.href}>{project.title}</a>
                </h3>
                <p className="project-subtitle">{project.subtitle}</p>
                <p>{project.description}</p>
                <div className="project-card-links">
                  {project.links.map((link) =>
                    link.disabled ? (
                      <span key={link.label} className="text-link disabled">
                        {link.label} coming soon
                      </span>
                    ) : (
                      <a key={link.label} className="text-link" href={link.href}>
                        {link.label}
                        <ArrowUpRight size={15} strokeWidth={2.2} />
                      </a>
                    ),
                  )}
                </div>
              </div>
            </article>
          ))}
        </div>
      </motion.section>

      <motion.section className="section contact-section" id="contact" {...appear}>
        <div>
          <div className="section-label">Contact</div>
          <h2>Team contact</h2>
        </div>
        <div className="contact-card contact-list-card">
          {aboutInfo.members.map((member) => (
            <p key={member.email}>
              <strong>{member.name}</strong>
              <a href={`mailto:${member.email}`}>{member.email}</a>
            </p>
          ))}
        </div>
      </motion.section>

      <footer className="site-footer">
        <strong>{siteInfo.name}</strong>
        <span>© 2026 Spiral Hand. All rights reserved.</span>
      </footer>
    </div>
  );
}
