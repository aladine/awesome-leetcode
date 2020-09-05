import java.util.*

class Solution16Jun {

    // Regex for digit from 0 to 255. 
    val zeroTo255 = "([0-9]|[1-9]\\d{1}|1\\d{2}|2[0-4]\\d|25[0-5])"
    val fourHexa = "([0-9A-Fa-f]+)" // "([0-9A-Fa-f]{1,2,3,4})"

    val rgv4 = zeroTo255 + "\\." + zeroTo255 + "\\." + zeroTo255 + "\\." + zeroTo255
    val rgv6 = fourHexa + ":" + fourHexa + ":" + fourHexa + ":" + fourHexa + ":" + fourHexa + ":" + fourHexa + ":" + fourHexa + ":" + fourHexa
    val v4Reg = Regex(rgv4)
    val v6Reg = Regex(rgv6)

    fun isValidIPv6(ip: String): String {
        ip.split(':').forEach {
            when {
                it.length > 4 -> return "Neither"
                !it.contains(Regex(fourHexa)) -> return "Neither"
            }
        }
        return "IPv6"
    }

    fun validIPAddress(IP: String): String {
        return when {
            v4Reg.matches(IP) -> "IPv4"
            v6Reg.matches(IP) -> "IPv6"
            // IP.split(':').size == 8 -> isValidIPv6(IP)
            else -> "Neither"
        }
    }
}

/*fun validIPAddress(IP: String): String {
    return when {
        IP.split('.').size == 4 -> isValidIPv4(IP) //         String[] ipv4 = IP.split("\\.",-1) in java
        IP.split(':').size == 8 -> isValidIPv6(IP)
        else -> "Neither"
    }
}

fun isValidIPv4(ip: String): String{
    ip.split('.').forEach {
        when{
            it.length > 3  -> return "Neither"
            !it.contains(Regex("^[0-9]+\$")) -> return "Neither"
            it.length != 1 && it.length != it.trimStart('0').length -> return "Neither"
            it.toInt() > 255 || it.toInt() < 0 -> return "Neither"
        }
    }
    return "IPv4"
}

fun isValidIPv6(ip: String): String{
    ip.split(':').forEach {
        when{
            it.length > 4 -> return "Neither"
            !it.contains(Regex("^[0-9A-Fa-f]+\$")) -> return "Neither"
        }
    }
    return "IPv6"
} */
