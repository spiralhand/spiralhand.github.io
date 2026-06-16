import { useEffect, useState } from 'react';
import { Navigation } from './components/Navigation';
import { About } from './pages/About';
import { Home } from './pages/Home';
import { PdsJoint } from './pages/PdsJoint';

function parseRoute() {
  const hash = window.location.hash.replace(/^#/, '');
  if (!hash.startsWith('/')) {
    return '/';
  }

  return hash.split('?')[0].split('#')[0] || '/';
}

function parseAnchor() {
  const hash = window.location.hash.replace(/^#/, '');
  if (!hash) {
    return undefined;
  }

  if (!hash.startsWith('/')) {
    return hash;
  }

  return hash.split('#')[1];
}

export default function App() {
  const [route, setRoute] = useState(parseRoute);

  useEffect(() => {
    const updateRoute = () => {
      setRoute(parseRoute());
      window.setTimeout(() => {
        const anchor = parseAnchor();
        if (anchor) {
          document.getElementById(anchor)?.scrollIntoView({ behavior: 'smooth', block: 'start' });
        } else {
          window.scrollTo({ top: 0, behavior: 'smooth' });
        }
      }, 0);
    };

    window.addEventListener('hashchange', updateRoute);
    updateRoute();
    return () => window.removeEventListener('hashchange', updateRoute);
  }, []);

  const Page = route === '/projects/pds-joint' ? PdsJoint : route === '/about' ? About : Home;

  return (
    <>
      <Navigation />
      <main>
        <Page />
      </main>
    </>
  );
}
