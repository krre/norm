use std::fs::File;
use std::io::BufReader;
use std::io::Bytes;

pub type BytesIter = Bytes<BufReader<File>>;
pub type Type = u8;

pub trait Token {
    fn deserialize(&mut self, bytes: &mut BytesIter);

    fn token_type(&self) -> Type;
}
