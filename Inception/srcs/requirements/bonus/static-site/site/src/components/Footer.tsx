export default function Footer() {
  return (
    <footer style={{
      background: "var(--accent)",
      color: "white",
      padding: "2rem",
      textAlign: "center"
    }}>
      <p>© {new Date().getFullYear()} Sebastião De Carvalho — 42_Luanda</p>
    </footer>
  );
}
