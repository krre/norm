use clap::{Args, Parser, Subcommand};

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

        #[command(flatten)]
        target: Target,
    },
    /// Build project
    Build,
}

#[derive(Args, Debug)]
#[group(multiple = false)]
struct Target {
    /// Binary target
    #[arg(long)]
    bin: bool,
    /// Library target
    #[arg(long)]
    lib: bool,
}

fn create_binary(name: String) {
    println!("Create binary `{name}`");
}

fn create_library(name: String) {
    println!("Create library `{name}`");
}

fn main() {
    let cli = Cli::parse();

    match cli.command {
        Commands::Create { name, target } => {
            if target.lib {
                create_library(name);
            } else {
                create_binary(name);
            }
        }
        Commands::Build => {
            println!("Building");
        }
    }
}
