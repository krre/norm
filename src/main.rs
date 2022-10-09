use std::env;
mod compiler;
mod project;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let args: Vec<String> = env::args().collect();

    if args.len() == 1 {
        println!("Usage: normc [options] file");
        return Result::Ok(());
    }

    compiler::run(&args[1])?;

    return Ok(());
}
