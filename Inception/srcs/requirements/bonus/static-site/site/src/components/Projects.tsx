const projects = [
  {
    name: 'Libft',
    link: 'https://github.com/Disaster-Loki/42_Cursus/tree/main/Libft',
    description: 'A foundational C library that reimplements standard functions like strlen, memcpy, atoi, and more.',
    status: '✅',
  },
  {
    name: 'Printf',
    link: 'https://github.com/Disaster-Loki/42_Cursus/tree/main/Printf',
    description: 'My implementation of the printf function in C, including flags, format specifiers, and variadic arguments.',
    status: '✅',
  },
  {
    name: 'Born2beroot',
    link: 'https://github.com/Disaster-Loki/42_Cursus/tree/main/Born2beroot',
    description: 'A system administration project that sets up a secure virtual machine with UFW, SSH, and monitoring tools.',
    status: '✅',
  },
  {
    name: 'Get Next Line',
    link: 'https://github.com/Disaster-Loki/42_Cursus/tree/main/Get_Next_Line',
    description: 'Reads a line from a file descriptor efficiently. Handles multiple FDs, buffer sizes, and memory management.',
    status: '✅',
  },
  {
    name: 'Minitalk',
    link: 'https://github.com/Disaster-Loki/42_Cursus/tree/main/Minitalk',
    description: 'A small messaging system using Unix signals to send strings between two processes.',
    status: '✅',
  },
  {
    name: 'Push Swap',
    link: 'https://github.com/Disaster-Loki/42_Cursus/tree/main/Push_swap',
    description: 'An algorithmic challenge: sorting numbers using only stack operations with optimal efficiency.',
    status: '✅',
  },
  {
    name: 'So_long',
    link: 'https://github.com/Disaster-Loki/42_Cursus/tree/main/So_long',
    description: 'A 2D game using MinilibX where the player collects items and exits the map avoiding enemies.',
    status: '✅',
  },
  {
    name: 'Philosophers',
    link: 'https://github.com/Disaster-Loki/42_Cursus/tree/main/Philosophers',
    description: 'Multithreading project simulating the classic Dining Philosophers problem using mutexes and threads.',
    status: '✅',
  },
  {
    name: 'Minishell',
    link: 'https://github.com/Disaster-Loki/Minishell',
    description: 'A Bash-like shell written in C that supports pipes, redirections, built-ins, and environment management.',
    status: '✅',
  },
  {
    name: 'Cub3D',
    link: 'https://github.com/Disaster-Loki/Cub3D',
    description: 'A 3D raycasting engine using MinilibX, creating a Wolfenstein-style first-person shooter.',
    status: '✅',
  },
  {
    name: 'NetPractice',
    link: 'https://github.com/Disaster-Loki/42_Cursus/tree/main/NetPractice',
    description: 'A TCP/IP challenge where you solve networking tasks like IP addressing, subnetting, and routing.',
    status: '✅',
  },
  {
    name: 'CPP Modules (00-09)',
    link: 'https://github.com/Disaster-Loki/42_Cursus/tree/main/CPP%20Modules',
    description: 'A series of object-oriented projects in C++ covering classes, inheritance, polymorphism, and templates.',
    status: '✅',
  },
];

const Projects = () => {
  return (
    <section className="section" id="projects">
      <h2>🚀 42 Cursus Projects</h2>
      <div className="projects-grid">
        {projects.map((proj) => (
          <a
            className="project-card"
            key={proj.name}
            href={proj.link}
            target="_blank"
            rel="noreferrer"
          >
            <div className="project-card-header">
              <h3>{proj.name}</h3>
              <span className="status">{proj.status}</span>
            </div>
            <p>{proj.description}</p>
          </a>
        ))}
      </div>
    </section>
  );
};

export default Projects;
