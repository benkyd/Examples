# node-dtdns-updater

This is a simple Client Updater for [DtDNS.com](http://dtdns.com).  

Install the dependencies with : `npm install`  
Launch it with : `node index.js`  
With the `-v` argument it logs everything.  

The first time the program launches, a `config.json` file will be created, you'll have to configure your DtDNS credentials and the update delay.  
In ip, leave `""` to point to the current ip.  

See [DtDNS api info](https://www.dtdns.com/dtsite/updatespec) for more info.

## License
MIT (SEE LICENSE FILE)