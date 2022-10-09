use super::project;

pub fn run(file_path: &String) -> Result<(), Box<dyn std::error::Error>> {
    let project = project::Project::new();
    project.read(file_path)?;
    Ok(())
}
