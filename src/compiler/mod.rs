pub fn run(file_path: &String) -> Result<(), Box<dyn std::error::Error>> {
    let file = std::fs::File::open(file_path)?;
    Ok(())
}
