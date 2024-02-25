use clap::{Parser, Subcommand};

#[derive(Parser, Debug)]
#[command(about = "Norm managing CLI tool", version, long_about = None)]
struct Cli {
    #[command(subcommand)]
    command: Commands,
}

#[derive(Subcommand, Debug)]
enum Commands {
    /// Create new project
    Create {
        /// Project name
        #[arg(required = true)]
        name: String,
        /// Binary target
        #[arg(long)]
        bin: bool,
        /// Library target
        #[arg(long)]
        lib: bool,
    },
    /// Build project
    Build,
}

fn main() {
    let cli = Cli::parse();

    match cli.command {
        Commands::Create { name, bin, lib } => {
            println!("Creating {name} {bin} {lib}");
        }
        Commands::Build => {
            println!("Building");
        }
    }
}
