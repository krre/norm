use normlib::project::Target;

pub fn create(name: &str, target: Target) -> Result<(), String> {
    if let Err(err) = normlib::project::create(name, target) {
        return Err(format!("Can't create project: {}", err.kind()));
    }

    Ok(())
}

pub fn build() -> Result<(), String> {
    if let Err(err) = normlib::project::build() {
        return Err(format!("Can't build project: {}", err.kind()));
    }

    Ok(())
}

pub fn run() -> Result<(), String> {
    if let Err(err) = normlib::project::run() {
        return Err(format!("Can't run project: {}", err.kind()));
    }

    Ok(())
}
