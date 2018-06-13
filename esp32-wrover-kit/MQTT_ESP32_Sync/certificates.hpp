/* 
 *  For the certificates and the keys on this page, paste everything
 *  between the 'R"(' and ')"', including any lines with hyphens.
 *  
 *  Ensure you do not add or clip any lines or whitespace when pasting.
 */


/* 
 *  DigiCert Root Certificate.  
 *  
 *  If this certificate does not work, retreive the latest with (*NIX):
 *  
 *  openssl s_client -showcerts -connect mqtt-sync.us1.twilio.com:8883 -cipher ECDHE-ECDSA-AES128-GCM-SHA256 < /dev/null
 *  
 *  ... and pick the last certificate in the chain.
 */
const char* root_cert = R"(-----BEGIN CERTIFICATE-----
-----END CERTIFICATE-----)";


/*  Client Key: Unencrypted.
 *  
 *  Download the client key from Twilio after you create the 
 *  certificate, then unencrypt it using the passphrase 
 *  displayed on the screen.  On *NIX, this is:
 *  
 *  openssl rsa -in  CYxxxxxxxxxx.key -out CYxxxxxxxxxx.key.decrypted
 *  
 *  Paste the results below between the '()' inside the double quotes
 *  and make sure there is no whitespace.
 */
const char* client_key = R"(-----BEGIN RSA PRIVATE KEY-----
-----END RSA PRIVATE KEY-----)";

/*  Client Certificate
 *  
 *  Paste the certificate below between the '()' inside the 
 *  double quotes, and make sure there is no whitespace.
 */
const char* client_cert = R"(-----BEGIN CERTIFICATE-----
-----END CERTIFICATE-----)";
