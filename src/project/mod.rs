pub struct Project {}

impl Project {
    pub fn new() -> Self {
        Self {}
    }

    pub fn read(self, file_path: &String) -> Result<(), Box<dyn std::error::Error>> {
        let file = std::fs::File::open(file_path)?;
        Ok(())
    }
}
