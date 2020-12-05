fun lexemTree(s: List<String>):exprNode<String> {
    var header = exprNode<String>("")
    var current = header
    for (i in 0 until s.size) {
        when (s[i]) {
            "PLUS" -> {
                var newNode = exprNode<String>("+")
                current.parent = newNode
                newNode.setLhs(current)
                current = newNode
            }
            "MINUS" -> {
                var newNode = exprNode<String>("-")
                current.parent = newNode
                newNode.setLhs(current)
                current = newNode
            }
            "TIMES" -> {
                var newNode = exprNode<String>("*")
                if (current.value != "^"){
                    newNode.parent = current
                    newNode.setLhs(current.getRhs())
                    current.setRhs(newNode)
                    current = newNode
                }
                else {
                    current.parent = newNode
                    newNode.setLhs(current)
                    current = newNode
                }
            }
            "DIVIDES" -> {

            }
            "POWER" -> {

            }
            "LPAREN" -> {
            }
            "RPAREN" -> {
            }
            "PI" -> {
            }
            "E" -> {
            }
            else -> {
                var newNode = numNode<String>(s[i].substring(7, s[i].indexOf(")")))
                newNode.parent = current
                if (current.getLhs() == current) {
                    current.setLhs(newNode)
                } else {
                    current.setRhs(newNode)
                }
            }
        }
    }
}
