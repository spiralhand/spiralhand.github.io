import { Mail } from 'lucide-react';
import { MemphisShape } from '../components/MemphisShape';
import { aboutInfo, siteInfo } from '../content/site';

export function About() {
  return (
    <div className="page about-page">
      <section className="about-hero poster-grid">
        <MemphisShape variant="dots" className="shape-one" />
        <MemphisShape variant="checker" className="shape-two" />
        <div>
          <p className="eyebrow">{aboutInfo.eyebrow}</p>
          <h1>{aboutInfo.title}</h1>
          <p className="about-intro">{aboutInfo.intro}</p>
          <p className="about-affiliation">{aboutInfo.affiliation}</p>
        </div>
      </section>

      <section className="section team-section">
        <div className="section-heading compact-heading">
          <div>
            <div className="section-label">Team</div>
            <h2>Project members</h2>
          </div>
        </div>

        <div className="team-grid">
          {aboutInfo.members.map((member) => (
            <article className="team-card" key={member.email}>
              <h3>{member.name}</h3>
              <a href={`mailto:${member.email}`}>
                <Mail size={18} strokeWidth={2.2} />
                {member.email}
              </a>
            </article>
          ))}
        </div>
      </section>

      <footer className="site-footer">
        <a href="#/">Back to {siteInfo.name}</a>
        <span>© 2026 Spiral Hand. All rights reserved.</span>
      </footer>
    </div>
  );
}
