use std::io::{BufReader, Read};

use self::token::Token;
pub mod header;
pub mod token;

pub struct Project {
    pub header: header::Header,
}

impl Project {
    pub fn new() -> Self {
        Self {
            header: header::Header::new(),
        }
    }

    pub fn read(&mut self, file_path: &String) -> Result<(), Box<dyn std::error::Error>> {
        let file = std::fs::File::open(file_path)?;
        let buf_reader = BufReader::new(file);
        let mut bytes = buf_reader.bytes();
        self.header.deserialize(&mut bytes);
        Ok(())
    }
}
