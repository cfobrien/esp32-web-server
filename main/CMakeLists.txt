idf_component_register(SRCS "main.c" "file_server.c" "get_req.c"
                    INCLUDE_DIRS "."
                    EMBED_FILES "favicon.ico" "upload_script.html")

# Embed the server root certificate into the final binary
#
# (If this was a component, we would set COMPONENT_EMBED_TXTFILES here.)
#idf_component_register(SRCS "test.c"
#                    INCLUDE_DIRS "."
#                    EMBED_TXTFILES howsmyssl_com_root_cert.pem)