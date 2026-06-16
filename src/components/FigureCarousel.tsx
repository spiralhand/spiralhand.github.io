import { ChevronLeft, ChevronRight } from 'lucide-react';
import { useState } from 'react';
import type { MediaItem } from '../content/pdsJoint';

type FigureCarouselProps = {
  items: MediaItem[];
};

export function FigureCarousel({ items }: FigureCarouselProps) {
  const [activeIndex, setActiveIndex] = useState(0);
  const activeItem = items[activeIndex];

  const showPrevious = () => {
    setActiveIndex((index) => (index === 0 ? items.length - 1 : index - 1));
  };

  const showNext = () => {
    setActiveIndex((index) => (index + 1) % items.length);
  };

  return (
    <div className="figure-carousel">
      <div className="figure-carousel-stage">
        <button className="carousel-arrow carousel-arrow-left" type="button" onClick={showPrevious} aria-label="Show previous figure">
          <ChevronLeft size={28} strokeWidth={2.4} />
        </button>
        <div className="carousel-media-frame" data-fit={activeItem.fit ?? 'contain'}>
          {activeItem.kind === 'video' ? (
            <video src={activeItem.src} controls playsInline preload="metadata" />
          ) : (
            <img src={activeItem.src} alt={activeItem.title} />
          )}
        </div>
        <button className="carousel-arrow carousel-arrow-right" type="button" onClick={showNext} aria-label="Show next figure">
          <ChevronRight size={28} strokeWidth={2.4} />
        </button>
      </div>

      <div className="figure-carousel-caption">
        <span>
          {String(activeIndex + 1).padStart(2, '0')} / {String(items.length).padStart(2, '0')}
        </span>
        <div>
          <h3>{activeItem.title}</h3>
          <p>{activeItem.description}</p>
        </div>
      </div>

      <div className="figure-carousel-dots" aria-label="Figure selector">
        {items.map((item, index) => (
          <button
            key={item.title}
            className={index === activeIndex ? 'is-active' : ''}
            type="button"
            onClick={() => setActiveIndex(index)}
            aria-label={`Show figure ${index + 1}: ${item.title}`}
          />
        ))}
      </div>
    </div>
  );
}
