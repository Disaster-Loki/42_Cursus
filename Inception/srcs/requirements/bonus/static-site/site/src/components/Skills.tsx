const skills = [
  { name: 'C, C++', level: 80 },
  { name: 'Shell Scripting (Bash)', level: 70 },
  { name: 'Makefile', level: 70 },
  { name: 'Networking (TCP/IP)', level: 75 },
  { name: 'Kernel Concepts', level: 65 },
];

const Skills = () => {
  return (
    <section className="section" id="skills">
      <h2>🛠️ Skills & Tools</h2>
      <div className="skills-container">
        {skills.map((skill) => (
          <div className="skill-block" key={skill.name}>
            <div className="skill-info">
              <span className="skill-name">{skill.name}</span>
              <span className="skill-percentage">{skill.level}%</span>
            </div>
            <div className="skill-bar">
              <div
                className="skill-fill"
                style={{ width: `${skill.level}%` }}
              ></div>
            </div>
          </div>
        ))}
      </div>
    </section>
  );
};

export default Skills;
