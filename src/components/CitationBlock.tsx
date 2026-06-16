import { useState } from 'react';
import { Check, Copy } from 'lucide-react';

type CitationBlockProps = {
  citation: string;
};

export function CitationBlock({ citation }: CitationBlockProps) {
  const [copied, setCopied] = useState(false);

  const copyCitation = async () => {
    await navigator.clipboard.writeText(citation);
    setCopied(true);
    window.setTimeout(() => setCopied(false), 1600);
  };

  return (
    <section className="section citation-section" id="citation">
      <div className="section-label">Citation</div>
      <div className="citation-card">
        <div>
          <p className="eyebrow">BibTeX</p>
          <h2>Cite the PDS Joint work</h2>
        </div>
        <button className="copy-button" type="button" onClick={copyCitation}>
          {copied ? <Check size={18} /> : <Copy size={18} />}
          {copied ? 'Copied' : 'Copy BibTeX'}
        </button>
        <pre>{citation}</pre>
      </div>
    </section>
  );
}
