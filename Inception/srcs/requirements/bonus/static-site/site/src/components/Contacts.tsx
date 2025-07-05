import { FaGithub, FaFacebook, FaInstagram, FaDiscord, FaPhoneAlt } from 'react-icons/fa';

const Contact = () => {
  return (
    <section className="section" id="contact">
      <h2>📬 Let’s Connect!</h2>
      <p style={{ maxWidth: '600px', marginBottom: '1rem' }}>
        Whether you're interested in collaborating, chatting about code, or just saying hi — feel free to reach out! I'm always available for tech talk or project ideas. You can find me on these platforms:
      </p>

      <div className="contact-links">
        <a href="https://github.com/Disaster-Loki" target="_blank" rel="noreferrer" aria-label="GitHub">
          <FaGithub />
        </a>
        <a href="https://facebook.com/agencehackers" target="_blank" rel="noreferrer" aria-label="Facebook">
          <FaFacebook />
        </a>
        <a href="https://discord.com/channels/" target="_blank" rel="noreferrer" aria-label="Discord">
          <FaDiscord />
        </a>
        <a href="https://www.instagram.com/agentehackers/" target="_blank" rel="noreferrer" aria-label="Instagram">
          <FaInstagram />
        </a>
      </div>

      <div className="phone">
        <FaPhoneAlt /> <span>+244 925 033 781 (24h/24)</span>
      </div>
    </section>
  );
};

export default Contact;
