# ft_ssl_md5

OpenSSL is a cryptographic toolkit library written C that is used to secure communications over computer networks. It implements the Secure Sockets Layer (SSL) and
Transport Layer Security (TLS) network protocols to protect against eavesdropping
and verify identities during network communication.
You must create a program named ft_ssl that will recreate part of the OpenSSL
functionality. Take care to do it well; the other projects in this series will build directly
onto this program.
For this project, you will implement the md5 and sha256 hashing functions.

```sh
$ usage: ft_ssl command [command opts] [command args]
```
# Command options

| Option | Description |
| ------ | ------ |
| -p | echo `STDIN` to `STDOUT` and append the checksum to `STDOUT` |
| -q | quiet mode |
| -r | reverse the format of the output |
| -s | print the sum of the given string |

# Algorithms

MD5 is a cryptographic hash function. It is short for "Message Digest 5". It has found to
contain several vulnerabilities, but can still be safely used as a checksum to verify data
integrity against unintentional corruption.

![alt text](https://raw.githubusercontent.com/lisov1y/ft_ssl_md5/master/img/md5_img.png)

SHA-256 is one of the functions in the SHA (Secure Hash Algorithms) family. The SHA
algorithms were designed by the NSA. SHA-512 is currently used in part of the process
to authenticate Debian software packages.

![alt text](https://raw.githubusercontent.com/lisov1y/ft_ssl_md5/master/img/sha256_img.png)
