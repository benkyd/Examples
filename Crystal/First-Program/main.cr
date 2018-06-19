require "discordcr"

token = "Bot NDIzNTkyMjczMTUxMDAwNTc2.DghCOQ.TITKUFX_WZDIh2j6kiprGTQ0Chw"
id = 423592273151000576_u64
prefix = '+'


client = Discord::Client.new(token: token, client_id: id)

client.on_message_create do |payload|
  if payload.content.starts_with? prefix
    client.create_message(payload.channel_id, "Pong!")
  end
end

client.run()