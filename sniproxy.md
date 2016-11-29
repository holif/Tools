apt-get update
apt-get upgrade
apt-get install autotools-dev cdbs debhelper dh-autoreconf dpkg-dev gettext libev-dev libpcre3-dev libudns-dev pkg-config fakeroot devscripts
apt-get install git
git clone https://github.com/dlundquist/sniproxy.git
cd sniproxy
./autogen.sh && dpkg-buildpackage

###这里请注意 不要直接复制运行###
dpkg -i ../sniproxy_<version>_<arch>.deb

###修改配置文件####
vi /etc/sniproxy.conf

user nobody
listen 80 {
	proto http
	table all_hosts
}
listen 443 {
	proto tls
	table all_hosts
}
table all_hosts {
	.*\.google\.com$ *
	.*\.google\.com\.hk$ *
	google.com google.com
	google.com.hk google.com.hk
	.*\.gstatic\.com$ *
	.*\.googleapis.com$ *
	.*\.googleusercontent.com$ *
	.*\.googlecode.com$ *
	.*\.google-analytics.com$ *
	.*\.ggpht.com$ *
	.*\.googlevideo.com$ *
	.*\.youtube.com$ *
	youtube.com youtube.com
	.*\.ytimg.com$ *
	.*\.appspot.com$ *
	.*\.blogger.com$ *
	blogger.com blogger.com
	.*\.twitter.com$ *
	twitter.com twitter.com
	.*\.twimg.com$ *
	.*\.facebook.com$ *
	facebook.com facebook.com
	.*\.fbcdn.net$ *
}

###启动sniproxy###
sniproxy  -c /etc/sniproxy.conf

###查看进程###
ps -A|grep sniproxy
