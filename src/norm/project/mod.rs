use std::fs;

pub mod application;
pub mod library;

pub enum Target {
    Application,
    Library,
}

pub fn create(name: &str, target: Target) -> Result<(), String> {
    if let Err(err) = create_project(name, target) {
        return Err(format!("Cann't to created project: {}", err.kind()));
    }

    Ok(())
}

fn create_project(name: &str, target: Target) -> std::io::Result<()> {
    fs::create_dir(name)?;

    match target {
        Target::Application => {
            fs::write(String::from(name) + "/app.norm", "@app")?;
        }
        Target::Library => {
            fs::write(String::from(name) + "/lib.norm", "@lib")?;
        }
    }

    Ok(())
}
