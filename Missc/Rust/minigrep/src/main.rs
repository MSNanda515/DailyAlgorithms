use std::{env};
use minigrep::Config;

fn main() {
    let args: Vec<String> = env::args().collect();
    let config = Config::build(&args).unwrap_or_else(|err| {
        panic!("Couldn't parse arguments: {err}")
    });
    if let Err(e) =  minigrep::run(config) {
        panic!("Application error: {e}");
    };
}