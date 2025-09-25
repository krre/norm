use std::fs;

pub mod application;
pub mod library;

pub const APP_FILE: &'static str = "app.norm";
pub const LIB_FILE: &'static str = "lib.norm";

pub enum Target {
    Application,
    Library,
}

pub fn create(name: &str, target: Target) -> Result<(), String> {
    if let Err(err) = create_project(name, target) {
        return Err(format!("Can't create project: {}", err.kind()));
    }

    Ok(())
}

pub fn build() -> Result<(), String> {
    if let Ok(res) = fs::exists(APP_FILE)
        && res
    {
        build_project(APP_FILE);
        return Ok(());
    }

    if let Ok(res) = fs::exists(LIB_FILE)
        && res
    {
        build_project(LIB_FILE);
        return Ok(());
    }

    Err(String::from("Directory is not Norm project"))
}

pub fn run() -> Result<(), String> {
    if let Ok(res) = fs::exists(APP_FILE)
        && res
    {
        println!("Application runned...");
        return Ok(());
    }

    Err(String::from("Directory is not Norm application project"))
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

fn build_project(file_name: &str) {
    println!("Build file {}", file_name);
    fs::create_dir("build").ok();
}
