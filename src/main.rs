use std::env;
mod compiler;
mod project;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let args: Vec<String> = env::args().collect();

    if args.len() == 1 {
        println!("Usage: norm [options] file");
        return Ok(());
    }

    compiler::run(&args[1])?;

    return Ok(());
}
