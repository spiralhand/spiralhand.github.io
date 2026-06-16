type MemphisShapeProps = {
  variant?: 'dots' | 'sun' | 'squiggle' | 'checker';
  className?: string;
};

export function MemphisShape({ variant = 'dots', className = '' }: MemphisShapeProps) {
  return <span aria-hidden="true" className={`memphis-shape ${variant} ${className}`} />;
}
