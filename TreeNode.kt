open class numNode<T>(value:T){
    var value:T = value
    var parent: numNode<T>? = null

}

class exprNode<String>(value:String) : numNode<String>(value){

    var children:MutableList<numNode<String>> = mutableListOf()

    fun addChild(node:numNode<String>) {
        children.add(node)
        node.parent = this
    }

    fun getLhs(): numNode<String> {
        if (this.children != null) {
            return this.children[0]
        }

        else{
            return this
        }

    }

    fun getRhs(): numNode<String> {
        if (this.children != null) {
            return this.children[1]
        }

        else{
            return this
        }

    }
}
