const SHA256 = require('crypto-js/sha256')

class Block{
  constructor(index, timestamp, data, previousHash='') {
    this.index = index;
    this.timestamp = timestamp;
    this.data = data;
    this.previousHash =  previousHash;
    this.hash = this.calculateHash();
  }

  calculateHash() {
    return SHA256(this.index + this.previousHash + this.timestamp + JSON.stringify(this.data)).toString();
  }
}

class Blockchain {
  constructor() {
    this.chain = [this.createGenesisBlock()];

  }

  // creates the first genesis block
  createGenesisBlock() {
    return new Block(0, "08/05/2021", "Genesis Block", "000");
  }

  // Returns the last block from the blockchain
  getLatestBlock() {
    return this.chain[this.chain.length - 1];
  }

  // adds a new block at the end of the block after recalculating the hash
  addBlock(newBlock) {
    newBlock.previousHash = this.getLatestBlock().hash;
    newBlock.hash = newBlock.calculateHash();
    this.chain.push(newBlock);
  }

  // validates the integrity of blockchain
  isChainValid() {
    for (let i = 1; i < this.chain.length; i++) {
      const currentBlock = this.chain[i];
      const previousBlock = this.chain[i-1];
      if (currentBlock.previousHash !== previousBlock.hash || 
        currentBlock.hash !== currentBlock.calculateHash()) {
        return false;
      }
    }
    return true;
  }
}



let savjeecoin = new Blockchain();
savjeecoin.addBlock(new Block(1, "10/10/2020", {amount: 4}));
savjeecoin.addBlock(new Block(2, "12/10/2020", {amount: 10}));

console.log("Is blockchain valid: " + savjeecoin.isChainValid());

savjeecoin.chain[1].data = {amount: 100};

console.log("Is blockchain valid: " + savjeecoin.isChainValid());
// console.log(JSON.stringify(savjeecoin, null, 4));
