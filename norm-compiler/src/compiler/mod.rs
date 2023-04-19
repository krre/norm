use super::project;

pub fn run(file_path: &String) -> Result<(), Box<dyn std::error::Error>> {
    let mut project = project::Project::new();
    project.read(file_path)?;
    compile(&project);
    Ok(())
}

fn compile(project: &project::Project) {}
