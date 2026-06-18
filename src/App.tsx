import { useEffect, useState } from 'react';
import { Navigation } from './components/Navigation';
import { About } from './pages/About';
import { Home } from './pages/Home';
import { PdsJoint } from './pages/PdsJoint';

function parseRoute() {
  return window.location.pathname || '/';
}

function parseAnchor() {
  return window.location.hash.replace(/^#/, '') || undefined;
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

    window.addEventListener('popstate', updateRoute);
    window.addEventListener('hashchange', updateRoute);
    updateRoute();
    return () => {
      window.removeEventListener('popstate', updateRoute);
      window.removeEventListener('hashchange', updateRoute);
    };
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
