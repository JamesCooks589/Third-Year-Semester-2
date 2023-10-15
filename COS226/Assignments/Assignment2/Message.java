public class Message {
    private final String message;
    private final String recipient;
    private final String sender;
    private final String messageId;

    public Message(String message, String recipient, String sender, String messageId) {
        this.message = message;
        this.recipient = recipient;
        this.sender = sender;
        this.messageId = messageId;
    }

    public String getMessage() {
        return message;
    }

    public String getRecipient() {
        return recipient;
    }

    public String getSender() {
        return sender;
    }

    public String getMessageId() {
        return messageId;
    }
}
