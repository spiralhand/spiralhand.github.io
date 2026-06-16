import { ArrowUpRight } from 'lucide-react';
import type { ProjectLink } from '../content/pdsJoint';

type LinkButtonProps = ProjectLink & {
  variant?: 'primary' | 'secondary' | 'ink';
};

export function LinkButton({ label, href, status = 'ready', variant = 'secondary' }: LinkButtonProps) {
  if (status === 'coming-soon') {
    return (
      <span className={`button button-${variant} is-disabled`} aria-disabled="true">
        {label} coming soon
      </span>
    );
  }

  return (
    <a className={`button button-${variant}`} href={href}>
      {label}
      <ArrowUpRight size={18} strokeWidth={2.2} />
    </a>
  );
}
