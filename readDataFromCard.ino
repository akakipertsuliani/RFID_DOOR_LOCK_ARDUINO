void readAllData() {
  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF; // Using default key for authentication

  // Loop through all 16 sectors
  for (byte sector = 0; sector < 16; sector++) {
    Serial.print(F("Sector ")); Serial.print(sector); Serial.println(F(":"));
    // Loop through all blocks in the sector
    byte blocks = 4; // Each sector has 4 blocks
    for (byte block = 0; block < blocks; block++) {
      byte blockAddr = sector * blocks + block;
      byte buffer[18];
      byte size = sizeof(buffer);

      // Authenticate each sector before reading
      MFRC522::StatusCode status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, blockAddr, &key, &(mfrc522.uid));
      if (status != MFRC522::STATUS_OK) {
        Serial.print(F("Authentication failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return;
      }

      // Read the block
      status = mfrc522.MIFARE_Read(blockAddr, buffer, &size);
      if (status != MFRC522::STATUS_OK) {
        Serial.print(F("Reading failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return;
      }

      // Dump the block data
      Serial.print(F("Block ")); Serial.print(blockAddr); Serial.print(F(": "));
      dump_byte_array(buffer, 16);
    }
  }
}