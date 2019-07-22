#!/usr/bin/env python3
import binascii

def main():
    tx = input("Enter raw tx hex string: ")
    tx = binascii.unhexlify(tx)
    version = tx[:4]
    prev_tx = tx[4:36]
    # Little endian to big endian
    version = version[::-1]
    print("Version: {}".format(version.hex()))
    print("Prev tx: {}".format(prev_tx.hex()))



if __name__ == '__main__':
    main()
