import { UsersRound } from 'lucide-react';

const navItems = [
  { label: 'Home', href: '/' },
  { label: 'Projects', href: '/#projects' },
  { label: 'Contact', href: '/about' },
];

export function Navigation() {
  return (
    <header className="site-nav" aria-label="Main navigation">
      <a className="brand-lockup" href="/" aria-label="Spiral Hand home">
        <span className="brand-mark">S</span>
        <span>
          <strong>Spiral Hand</strong>
          <small>Research project</small>
        </span>
      </a>
      <nav>
        {navItems.map((item) => (
          <a key={item.label} href={item.href}>
            {item.label}
          </a>
        ))}
      </nav>
      <a className="nav-paper" href="/about">
        About Us
        <UsersRound size={16} strokeWidth={2.2} />
      </a>
    </header>
  );
}
