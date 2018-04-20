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
MIIElDCCA3ygAwIBAgIQAf2j627KdciIQ4tyS8+8kTANBgkqhkiG9w0BAQsFADBh
MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMRkwFwYDVQQLExB3
d3cuZGlnaWNlcnQuY29tMSAwHgYDVQQDExdEaWdpQ2VydCBHbG9iYWwgUm9vdCBD
QTAeFw0xMzAzMDgxMjAwMDBaFw0yMzAzMDgxMjAwMDBaME0xCzAJBgNVBAYTAlVT
MRUwEwYDVQQKEwxEaWdpQ2VydCBJbmMxJzAlBgNVBAMTHkRpZ2lDZXJ0IFNIQTIg
U2VjdXJlIFNlcnZlciBDQTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEB
ANyuWJBNwcQwFZA1W248ghX1LFy949v/cUP6ZCWA1O4Yok3wZtAKc24RmDYXZK83
nf36QYSvx6+M/hpzTc8zl5CilodTgyu5pnVILR1WN3vaMTIa16yrBvSqXUu3R0bd
KpPDkC55gIDvEwRqFDu1m5K+wgdlTvza/P96rtxcflUxDOg5B6TXvi/TC2rSsd9f
/ld0Uzs1gN2ujkSYs58O09rg1/RrKatEp0tYhG2SS4HD2nOLEpdIkARFdRrdNzGX
kujNVA075ME/OV4uuPNcfhCOhkEAjUVmR7ChZc6gqikJTvOX6+guqw9ypzAO+sf0
/RR3w6RbKFfCs/mC/bdFWJsCAwEAAaOCAVowggFWMBIGA1UdEwEB/wQIMAYBAf8C
AQAwDgYDVR0PAQH/BAQDAgGGMDQGCCsGAQUFBwEBBCgwJjAkBggrBgEFBQcwAYYY
aHR0cDovL29jc3AuZGlnaWNlcnQuY29tMHsGA1UdHwR0MHIwN6A1oDOGMWh0dHA6
Ly9jcmwzLmRpZ2ljZXJ0LmNvbS9EaWdpQ2VydEdsb2JhbFJvb3RDQS5jcmwwN6A1
oDOGMWh0dHA6Ly9jcmw0LmRpZ2ljZXJ0LmNvbS9EaWdpQ2VydEdsb2JhbFJvb3RD
QS5jcmwwPQYDVR0gBDYwNDAyBgRVHSAAMCowKAYIKwYBBQUHAgEWHGh0dHBzOi8v
d3d3LmRpZ2ljZXJ0LmNvbS9DUFMwHQYDVR0OBBYEFA+AYRyCMWHVLyjnjUY4tCzh
xtniMB8GA1UdIwQYMBaAFAPeUDVW0Uy7ZvCj4hsbw5eyPdFVMA0GCSqGSIb3DQEB
CwUAA4IBAQAjPt9L0jFCpbZ+QlwaRMxp0Wi0XUvgBCFsS+JtzLHgl4+mUwnNqipl
5TlPHoOlblyYoiQm5vuh7ZPHLgLGTUq/sELfeNqzqPlt/yGFUzZgTHbO7Djc1lGA
8MXW5dRNJ2Srm8c+cftIl7gzbckTB+6WohsYFfZcTEDts8Ls/3HB40f/1LkAtDdC
2iDJ6m6K7hQGrn2iWZiIqBtvLfTyyRRfJs8sjX7tN8Cp1Tm5gr8ZDOo0rwAhaPit
c+LJMto4JQtV05od8GiG7S5BNO98pVAdvzr508EIDObtHopYJeS4d60tbvVS3bR0
j6tJLp07kzQoH3jOlOrHvdPJbRzeXDLz
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
MIIEpQIBAAKCAQEA6xq9BLpt6o8o6SPKbY6h5SxLHUpLPECn2Op9+kcKJuV51Nh0
eqR82sPJ7tLO+TlmFQBB2K1b8yGE/IJiXR2PrdFRQtfhf9u+sSjBf4xDSwFozgWl
OWsFyP0WMi8wCdmZfnXOJMcGfT3znUnaBvzxoK9J8gwcWwqVXFCRx3TjsPZwzz4x
UHV4cbmYTvokfjfYLI7gmaeUe++Ciq5Z/xy5a6WY8fX5LftSoHwv4pa9/IFyit2t
ksNw+DDvUftdqneJkv32VCO80EZdFBUrQ8BGhrHn20IVVCh+2oL0iQXxFQrkzTe0
O5+XcQRjKBgD022cbq2C447V3v9TKHkUhwadXQIDAQABAoIBAHtGne4owxHG1zDI
L5CaxZEhVJGbLy/8xwYajsv5C/2xPdy5Uvor3bvoBa5Qo25TBo/kfqJa5GfsH4s3
4tPoeDowE2f1QqyEUM0cDboPlglyR74ff69HytTEwCq4S3weuTlyFBF8uo5ZObAz
1TrsztXuk9tzNjsWpZKuPIJVbD6ROPN/NLqIj411mtA1hXy9FF4SAwh8ofWB79vN
jfLDyiulB0ULc2xtqabmHsLfmd7mTHguTCk8a2VooHP0LH0x3oWOr/mdg511Ds2q
vrR6wgriE5udFkXWTnDyDQSnCh8DJL1yKmt32TP5zkmRNnIFTMnppCrZ+G581VW1
cE9P5ZECgYEA95onZ2Y+IrPmhL+pUyIrx7LuYkC60LeGJWiUQ9aAx33IN68DwzJf
e/MBGjIvzTVy0BepDm3lV4M+Gm1Zl3dShNkC0zFDRmKkPKaSVlhW9TV3IwThak9D
q9hujerbm5p19DSid9FKt9Gk+lIDWq4fiI+HaIcdOBvn7oOpPv1u2FsCgYEA8xQS
KxNE4LUOGv73+bhI2GaCHtqcaM5ONQLkZ/u4L+oduSbqR+wqOxCm/tsdoWAaBbh3
fLrmOtFS+lh7/HuRR2uKwVW7YkrDjwy+TpfYW7wOh3gt0Unfk97TAg6f/O6McvXr
n4sQNmW/4W+bYVY02NixuU2l1CvDuEylmC0vjqcCgYEA9rTuliRVvRYrlhGykVb2
8F/lDpkYi2aRjyyIrp9IaX12xaToxtGmOkaCzqs63elnoNgyZmIxpeTrOEHEhxsp
aZ0hJ3VqZvNaWeRO4yHaYzEGqCnwwJCCCPP6FAXzEzPwW4cmauRq4oVNMO4O0Ye1
e8gnT4txHbsQeaNOO6khjQkCgYEAlkhEa0lAfkSx8dLM8SEUOGY38Gdr6AgUpgWh
vQANgeIWelAq7EiAW4ASHuLNUOYfcIX5qa3LhXXA/XITRagHy8YbRSiB72UVvq08
Q07xvtVnji2o9gncJonOnyj3lOLPBowwHrVVUqxZk0DzKZyok6B1UIFHEwPzv0/z
2T+mdWUCgYEAtJlWMiVRM5BObFERxvNfDw7/DioUdo4LpqGUEvOmhKRhQNZBy6P2
6V2UBRH3Hq/lHl7vjKlh3mTrQKKLqUOtDJXNJy3MGoOa1++ph3w374u+eD5u3lQd
i9lpAzSFBSpR5iTvj2kww6tMPeW+k3sscQchym5B2Zt6c9n2dckRNI8=
-----END RSA PRIVATE KEY-----)";

/*  Client Certificate
 *  
 *  Paste the certificate below between the '()' inside the 
 *  double quotes, and make sure there is no whitespace.
 */
const char* client_cert = R"(-----BEGIN CERTIFICATE-----
MIID8TCCAtmgAwIBAgIBADANBgkqhkiG9w0BAQsFADCBkjErMCkGA1UEAwwiRkww
ZDM4NjNlMzE2ZDI0NjFjYjNjMWEwZGU3YmIwOWFhMjELMAkGA1UEBhMCVVMxEzAR
BgNVBAgMCkNhbGlmb3JuaWExFjAUBgNVBAcMDVNhbiBGcmFuY2lzY28xFDASBgNV
BAoMC1R3aWxpbyBJbmMuMRMwEQYDVQQLDApUd2lsaW8gUlREMB4XDTE4MDIyMzAx
NDgzNFoXDTE4MDIyMzAxNDgzNFowgZIxKzApBgNVBAMMIkZMMGQzODYzZTMxNmQy
NDYxY2IzYzFhMGRlN2JiMDlhYTIxCzAJBgNVBAYTAlVTMRMwEQYDVQQIDApDYWxp
Zm9ybmlhMRYwFAYDVQQHDA1TYW4gRnJhbmNpc2NvMRQwEgYDVQQKDAtUd2lsaW8g
SW5jLjETMBEGA1UECwwKVHdpbGlvIFJURDCCASIwDQYJKoZIhvcNAQEBBQADggEP
ADCCAQoCggEBAOsavQS6beqPKOkjym2OoeUsSx1KSzxAp9jqffpHCibledTYdHqk
fNrDye7Szvk5ZhUAQditW/MhhPyCYl0dj63RUULX4X/bvrEowX+MQ0sBaM4FpTlr
Bcj9FjIvMAnZmX51ziTHBn09851J2gb88aCvSfIMHFsKlVxQkcd047D2cM8+MVB1
eHG5mE76JH432CyO4JmnlHvvgoquWf8cuWulmPH1+S37UqB8L+KWvfyBcordrZLD
cPgw71H7Xap3iZL99lQjvNBGXRQVK0PARoax59tCFVQoftqC9IkF8RUK5M03tDuf
l3EEYygYA9NtnG6tguOO1d7/Uyh5FIcGnV0CAwEAAaNQME4wHQYDVR0OBBYEFPjE
9kXWVwK/gFq+jksmhveDekdwMB8GA1UdIwQYMBaAFPjE9kXWVwK/gFq+jksmhveD
ekdwMAwGA1UdEwQFMAMBAf8wDQYJKoZIhvcNAQELBQADggEBAHJOoyooX/NLkR8s
IKhiK7qX2VneU/fahQGDx3v2cYnTpxOw1SLprVYX9HsbJFHMDr3c3rygbF+APOZF
DnD6CYdu/v2XzptrM0TqDPkSwatQgPkoDi/n3NiNROFjzzy1+GMWY4xakQZo/rH7
BOxTJr4HCh5cGIyizpt3Fg7AIzCj+GcBT/HIDq6UhkOY61CrUGa4WF4NWrzRslve
niSy/NtgLckeAah8u/mr0qDayKK1U9DVtJCJYZnPbRIT3HX8LFadco8r2ahizSvE
+JsVf4c2J/0mmQbdoRDcyCyife8FRqkaxmRdAO0ewV8dDwI1rKVY7nUuif5DwkMD
Ks+IKjo=
-----END CERTIFICATE-----)";
