type MediaCardProps = {
  title: string;
  description: string;
  src: string;
  kind?: 'image' | 'video';
  tall?: boolean;
  fit?: 'contain' | 'cover';
};

export function MediaCard({ title, description, src, kind = 'image', tall = false, fit = 'contain' }: MediaCardProps) {
  return (
    <article className={`media-card ${tall ? 'media-card-tall' : ''}`}>
      <div className="media-frame" data-fit={fit}>
        {kind === 'video' ? (
          <video src={src} controls playsInline preload="metadata" />
        ) : (
          <img src={src} alt={title} loading="lazy" />
        )}
      </div>
      <div className="media-copy">
        <h3>{title}</h3>
        <p>{description}</p>
      </div>
    </article>
  );
}
