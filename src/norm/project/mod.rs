use std::fs;

use normlib::project::Target;

pub fn create(name: &str, target: Target) -> Result<(), String> {
    if let Err(err) = normlib::project::create(name, target) {
        return Err(format!("Can't create project: {}", err.kind()));
    }

    Ok(())
}

pub fn build() -> Result<(), String> {
    if let Ok(res) = fs::exists(normlib::project::APP_FILE)
        && res
    {
        build_project(normlib::project::APP_FILE);
        return Ok(());
    }

    if let Ok(res) = fs::exists(normlib::project::LIB_FILE)
        && res
    {
        build_project(normlib::project::LIB_FILE);
        return Ok(());
    }

    Err(String::from("Directory is not Norm project"))
}

pub fn run() -> Result<(), String> {
    if let Ok(res) = fs::exists(normlib::project::APP_FILE)
        && res
    {
        println!("Application runned...");
        return Ok(());
    }

    Err(String::from("Directory is not Norm application project"))
}

fn build_project(file_name: &str) {
    println!("Build file {}", file_name);
    fs::create_dir("build").ok();
}
