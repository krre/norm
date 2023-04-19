use super::token::{BytesIter, Token, Type};

pub struct Header {
    version: Version,
    token_type: Type,
}

pub struct Version {
    majour: u8,
    minor: u8,
    micro: u8,
}

impl Header {
    pub fn new() -> Self {
        Self {
            token_type: 0,
            version: Version {
                majour: 0,
                minor: 0,
                micro: 0,
            },
        }
    }
}

impl Token for Header {
    fn deserialize(&mut self, bytes: &mut BytesIter) {
        self.token_type = bytes.next().unwrap().unwrap();

        self.version.majour = bytes.next().unwrap().unwrap();
        self.version.minor = bytes.next().unwrap().unwrap();
        self.version.micro = bytes.next().unwrap().unwrap();
    }

    fn token_type(&self) -> Type {
        self.token_type
    }
}
