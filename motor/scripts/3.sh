#!/bin/bash
echo "	Host dev
	HostName 192.168.200.38
	User robot

Host *
    SendEnv LANG LC_*
    HashKnownHosts yes
    GSSAPIAuthentication yes
    StrictHostKeyChecking no
" >> /etc/ssh/ssh_config