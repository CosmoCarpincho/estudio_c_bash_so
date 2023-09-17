# Prueba de BEGIN y END 7.1.4.1 Startup adn Cleanup Actions


BEGIN { print "Analysis of \"li\""}

/li/ { ++n }

END { print "\"li\" appears in", n, "records." }

