use clap::{Args, Parser, Subcommand};

#[derive(Parser, Debug)]
#[command(about = "Command-line interface (CLI) for managing Norm code", version, long_about = None)]
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
    /// Application target
    #[arg(long)]
    app: bool,
    /// Library target
    #[arg(long)]
    lib: bool,
}

fn create_application(name: String) {
    println!("Create application `{name}`");
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
                create_application(name);
            }
        }
        Commands::Build => {
            println!("Building");
        }
    }
}
