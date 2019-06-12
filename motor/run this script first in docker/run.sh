#!/bin/bash
apt-get update -y
apt install openssh-client -y
echo "	Host dev
	HostName 192.168.200.38
	User robot

Host *
    SendEnv LANG LC_*
    HashKnownHosts yes
    GSSAPIAuthentication yes
" >> /etc/ssh/ssh_config