fn main() {
    if let Err(err) = norm::router::route() {
        eprintln!("{err}");
    }
}
