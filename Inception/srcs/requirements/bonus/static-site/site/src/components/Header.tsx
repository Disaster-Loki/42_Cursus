import { useTheme } from './ThemeContext';
import { Sun, Moon } from 'lucide-react';

export default function Header() {
  const { toggle, theme } = useTheme();

  return (
    <header className="header">
      <div className="header-left">
        <div className="logo">
          <span>SC</span>
        </div>
        <nav className="nav-links">
          <a href="#home">Home</a>
          <a href="#about">About</a>
          <a href="#skills">Skills</a>
          <a href="#projects">Projects</a>
          <a href="#contact">Contact</a>
        </nav>
      </div>
      <button className="theme-switcher" onClick={toggle} aria-label="Toggle Theme">
        {theme === 'light' ? <Moon size={20} /> : <Sun size={20} />}
      </button>
    </header>
  );
}
