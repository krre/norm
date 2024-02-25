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
        #[arg(required = true)]
        name: String,
    },
    /// Build project
    Build,
}

fn main() {
    let cli = Cli::parse();

    match cli.command {
        Commands::Create { name } => {
            println!("Creating {name}");
        }
        Commands::Build => {
            println!("Building");
        }
    }
}
